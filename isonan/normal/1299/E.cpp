#include <cstdio>
#include <algorithm>

int n,ind[801],ord[801],rnd[801],ans[801],p[801],nowmod,nowval[801],tem[801];
void out(int x){printf("%d ",rnd[x]);}
int que(std::vector<int>&vec){
	int ans=0;
#ifdef ISONAN
	for(int i=0;i<vec.size();i++)ans+=p[rnd[vec[i]]],printf("%d ",rnd[vec[i]]);
	printf("%d ",ans);
	printf("%d\n",(ans%vec.size()==0));
	return (ans%vec.size()==0);
#else
	printf("? %d ",vec.size());
	for(int i=0;i<vec.size();i++)out(vec[i]);
	putchar('\n');
	fflush(stdout); 
	scanf("%d",&ans);
	return ans;
#endif
}
void get(int k){
//	puts("get");
//	for(int i=1;i<=n;i++)printf("%d ",ind[i]);putchar('\n');
	std::vector<int>tem;
	for(int i=1;i<=n;i++)if(!ind[i])tem.push_back(i);
	int p1=0,p2=0;
	if(k==1){
		for(int i=1,ans;i<=n;i++)
			if(!ind[i]){
				std::vector<int>ttem;
				for(int j=0;j<tem.size();j++)if(tem[j]!=i)ttem.push_back(tem[j]);
				if(que(ttem)){
					if(p1){p2=i;break;}
					else p1=i;
				}
			}
		std::swap(p1,p2);
		ind[p1]=1,ind[p2]=n;
		ord[1]=p1,ord[n]=p2;
//		printf("%d %d %d %d\n",rnd[p1],rnd[p2],p1,p2);
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(!ind[i]&&nowval[i]==k%nowmod)++cnt;
		for(int i=1;i<=n;i++)
			if(!ind[i]&&nowval[i]==k%nowmod){
				std::vector<int>ttem;
				for(int j=0;j<tem.size();j++)if(tem[j]!=i)ttem.push_back(tem[j]);
				--cnt;
				if((!cnt)||que(ttem)){
					int u=k;
					ind[i]=u,ord[u]=i;
					break;
				}
			}
		cnt=0;
		for(int i=1;i<=n;i++)
			if(!ind[i]&&nowval[i]==(n-k+1)%nowmod)++cnt;
		for(int i=1;i<=n;i++)
			if(!ind[i]&&nowval[i]==(n-k+1)%nowmod){
				std::vector<int>ttem;
				for(int j=0;j<tem.size();j++)if(tem[j]!=i)ttem.push_back(tem[j]);
				--cnt;
				if((!cnt)||que(ttem)){
					int u=n-k+1;
					ind[i]=u,ord[u]=i;
					break;
				}
			}
	}
}
void getpar(){
	for(int i=1;i<=n;i++)
		if(!ind[i]){
			std::vector<int>tem;
			tem.push_back(ord[1]);
			tem.push_back(i);
			nowval[i]=que(tem);
		}
		else nowval[i]=(ind[i]&1);
}
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
void merge(int x){
	int bg=(x*nowmod)/gcd(nowmod,x);
	for(int i=1;i<=n;i++)
		for(int j=0;j<bg;j++)
			if(j%x==(::tem[i]%x)&&j%nowmod==nowval[i]){
				nowval[i]=j;
				break;
			}
	nowmod=bg;
}
int main(){
	scanf("%d",&n);
#ifdef ISONAN
	for(int i=1;i<=n;i++)p[i]=i;
#endif
	for(int i=1;i<=n;i++)rnd[i]=i;
	for(int i=1;i<=n*10;i++)std::swap(rnd[rand()%n+1],rnd[rand()%n+1]);
	if(n<=8){
		get(1);
		getpar();
		nowmod=2;
		for(int i=2;(i<<1)<=n;i++)
			get(i);
	}
	else{
		get(1);
		getpar();
		nowmod=2;
		get(2);
//		for(int i=1;i<=n;i++)printf("%d %d %d\n",rnd[i],ind[i],ord[ind[i]]);
		for(int i=1;i<=n;i++)
			if(!ind[i]){
				std::vector<int>tem;
				tem.push_back(i);
				tem.push_back(ord[1]);
				tem.push_back(ord[2]);
				if(que(tem))::tem[i]=0;
				else{
					if(n%3==1){
						tem.back()=ord[n];
						if(que(tem))::tem[i]=1;
						else ::tem[i]=2;
					}
					else{
						tem[1]=(n%3==2)?ord[n]:ord[n-1];
						if(que(tem))::tem[i]=2;
						else ::tem[i]=1;
					}
				}
			}
		merge(3);
		get(3);
		if(n%4==0)ord[4]=ord[n];
		else ord[4]=ord[n-2];
		for(int i=1;i<=n;i++)
			if(!ind[i]){
				for(int j=1;j<=4;j++)
					if(j%2==nowval[i]%2){
						::tem[i]=4-(10-j)%4;
					}
				for(int j=1;j<=4;j++)
					if(j%2==nowval[i]%2){
						std::vector<int>tem;
						tem.push_back(i);
						for(int k=1;k<=4;k++)if(j!=k)tem.push_back(ord[k]);
						if(que(tem))::tem[i]=4-(10-j)%4;
						break;
					}
			}
		merge(4);
		get(4);
		int p;
		for(int i=1;i<=n;i++)::tem[i]=0;
		for(int i=1;i<=n;i++)
			if(!ind[i]){
				std::vector<int>tem;
				tem.push_back(i);
				for(int j=1;j<=4;j++)tem.push_back(ord[j]);
				if(que(tem))::tem[i]=5,p=i;
			}
		for(int i=1;i<=n;i++)
			if(!ind[i]&&!::tem[i]){
				::tem[i]=4;
				for(int j=1;j<4;j++){
					std::vector<int>tem;
					tem.push_back(i);
					tem.push_back(p);
					for(int k=1;k<=4;k++)if(j!=k)tem.push_back(ord[k]);
					if(que(tem)){
						::tem[i]=j;
						break;
					}
				}
			}
		merge(5);
		for(int i=1;i<=n;i++)
			if(!ind[i]){
				int x=0;
				for(int j=1;j<=8;j++)if(j%4==nowval[i]%4)x^=(j%8);
//				printf("%d %d\n",nowval[i],x);
				for(int j=1;j<=8;j++)
					if((j+4)%8>=1&&(j+4)%8<=4&&j%4==nowval[i]%4){
						std::vector<int>tem;
						tem.push_back(i);
//						printf("Get %d : ",j);
						for(int k=1;k<=4;k++){
							tem.push_back(ord[n-k+1]);//,printf("%d ",n-k+1);
							if((j+4)%8!=k)tem.push_back(ord[k]);//,printf("%d ",k);
						}
//						putchar('\n');
						if(que(tem))::tem[i]=j;
						else ::tem[i]=x^j;
						break;
					}
			}
//		for(int i=1;i<=n;i++)printf("%d %d %d %d %d\n",::p[rnd[i]],ind[i],rnd[i],nowval[i],::tem[i]);
		merge(8);
		for(int i=5;(i<<1)<=n;i++)get(i);
	}
//	for(int i=1;i<=n;i++)printf("%d ",ind[i]);putchar('\n');
	for(int i=1;i<=n;i++)ans[rnd[i]]=ind[i];
	if(ans[1]>(n>>1))for(int i=1;i<=n;i++)ans[i]=n+1-ans[i];
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	fflush(stdout);
}
#include <cstdio>
#include <algorithm>

int t,n,p[1000001];
bool vis[1000001];
const int P=1000000007;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",p+i),vis[i]=0;
		int v=1,x=n,req=0;
		while(x%3!=0){
			v<<=1;
			x-=2;
			++req;
		}
		while(x){
			v=1ll*v*3%P;
			x-=3;
		}
		printf("%d ",v);
		int cnt1=0,cnt2=0,cnt4=0,c=0x7f7f7f7f;
		v=0;
		bool have3=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				int tem=i,len=0;
				while(!vis[tem]){
					++len;
					vis[tem]=1;
					tem=p[tem];
				}
				if(len==1)++cnt1;
				else if(len%3==2)++cnt2;
				else if(len%3==1)++cnt4;
				v+=((len+2)/3)-1;
				if(len==3||len>4)have3=1;
			}
		if(cnt4&&req==2){
			for(int i=0;i<cnt4;i++){
				int Cnt2=cnt2+2*i,Cnt1=cnt1+(cnt4-1-i);
				if(Cnt2>Cnt1)continue;
				c=std::min(c,-1+Cnt2+((Cnt1-Cnt2)/3)*2);
			}
		}
		for(int i=0;i<=cnt4;i++){
			int Cnt2=cnt2+2*i,Cnt1=cnt1+(cnt4-i);
			for(int j=0;j<=req;j++){
				if(Cnt2<j||cnt1<(req-j)*2)continue;
				Cnt2-=j,Cnt1-=(req-j)*2;
				int tem=0;
				if(Cnt2>Cnt1){
					tem=(Cnt2-Cnt1+2)/3;
					Cnt2-=tem,Cnt1+=tem*2;
				}
				c=std::min(c,req-j+Cnt2+tem+(Cnt1-Cnt2)/3*2);
				Cnt2+=tem,Cnt1-=tem*2;
				
				Cnt2+=j,Cnt1+=(req-j)*2;
			}
		}
		if(have3){
			++cnt1,++cnt2;
		if(cnt4&&req==2){
			for(int i=0;i<cnt4;i++){
				int Cnt2=cnt2+2*i,Cnt1=cnt1+(cnt4-1-i);
				if(Cnt2>Cnt1)continue;
				c=std::min(c,+Cnt2+((Cnt1-Cnt2)/3)*2);
			}
		}
		for(int i=0;i<=cnt4;i++){
			int Cnt2=cnt2+2*i,Cnt1=cnt1+(cnt4-i);
			for(int j=0;j<=req;j++){
				if(Cnt2<j||cnt1<(req-j)*2)continue;
				Cnt2-=j,Cnt1-=(req-j)*2;
				int tem=0;
				if(Cnt2>Cnt1){
					tem=(Cnt2-Cnt1+2)/3;
					Cnt2-=tem,Cnt1+=tem*2;
				}
				c=std::min(c,1+req-j+Cnt2+tem+(Cnt1-Cnt2)/3*2);
				Cnt2+=tem,Cnt1-=tem*2;
				
				Cnt2+=j,Cnt1+=(req-j)*2;
			}
		}
		--cnt1,--cnt2;
		if(cnt1){
			--cnt1,++cnt4;
		if(cnt4&&req==2){
			for(int i=0;i<cnt4;i++){
				int Cnt2=cnt2+2*i,Cnt1=cnt1+(cnt4-1-i);
				if(Cnt2>Cnt1)continue;
				c=std::min(c,1+Cnt2+((Cnt1-Cnt2)/3)*2);
			}
		}
		for(int i=0;i<=cnt4;i++){
			int Cnt2=cnt2+2*i,Cnt1=cnt1+(cnt4-i);
			for(int j=0;j<=req;j++){
				if(Cnt2<j||cnt1<(req-j)*2)continue;
				Cnt2-=j,Cnt1-=(req-j)*2;
				int tem=0;
				if(Cnt2>Cnt1){
					tem=(Cnt2-Cnt1+2)/3;
					Cnt2-=tem,Cnt1+=tem*2;
				}
				c=std::min(c,2+req-j+Cnt2+tem+(Cnt1-Cnt2)/3*2);
				Cnt2+=tem,Cnt1-=tem*2;
				
				Cnt2+=j,Cnt1+=(req-j)*2;
			}
		}
		}
		}
//		if(!cnt1&&!cnt4){
//			c=std::min(c,(cnt2-req));
//		}
//		if(c>n)c=std::min(c,(cnt1+2)/3);
		printf("%d\n",c+v);
	}
}
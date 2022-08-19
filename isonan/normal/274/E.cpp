#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define NE 1
#define NW 2
#define SE 3
#define SW 4

int x[1000001],y[1000001],n,m,k,X,Y;
std::vector<int>left[1000001],right[1000001];
std::set<std::pair<int,int> >set;
bool div2=0,cando=0;
char ch1,ch2;
char get(){
	char ch=getchar();
	while(ch<'A'||ch>'Z')ch=getchar();
	return ch;
}
long long ans=0;
#define check1 //printf("#%d %d\n$%d %d\n$%d %d\n*%d %d\n",a,*x,*x,a+b-*x,*x,*x-a+b,bb1,bb2);
void getans(int a,int b,int dir,int count){
//	printf("%d %d %d %d %d %d %I64d\n",a,b,dir,count,X,Y,ans);
	if(count==1)X=a,Y=b;
	count+=(a==X&&b==Y);
	if(count>3)return;
	if(dir==NE){
		auto x=std::lower_bound(left[a+b].begin(),left[a+b].end(),a)-1;
		if(count>1)ans+=a-(*x);
		int bb1=set.count(std::make_pair((*x)+1,a+b-(*x))),bb2=set.count(std::make_pair((*x),a+b-(*x)-1));
		check1
		if((bb1&&bb2)||(!bb1&&!bb2)){
			if(!cando)cando=1,count=2,X=*x+1,Y=a+b-*x-1,ans=0;
			getans(*x+1,a+b-(*x)-1,SW,count);
		}
		else if(bb1&&!bb2)getans(*x,a+b-(*x)-1,NW,count);
		else if(!bb1&&bb2)getans((*x)+1,a+b-(*x),SE,count);
	}
	else if(dir==SW){
		auto x=std::upper_bound(left[a+b].begin(),left[a+b].end(),a);
		if(count>1)ans+=(*x)-a;
		bool bb1=set.count(std::make_pair((*x)-1,a+b-(*x))),bb2=set.count(std::make_pair((*x),a+b-(*x)+1));
		check1
		if((bb1&&bb2)||(!bb1&&!bb2)){
			if(!cando)cando=1,count=2,X=*x-1,Y=a+b-*x+1,ans=0;
			getans(*x-1,a+b-(*x)+1,NE,count);
		}
		else if(bb1&&!bb2)getans(*x,a+b-(*x)+1,SE,count);
		else if(!bb1&&bb2)getans(*x-1,a+b-(*x),NW,count);
	}
	else if(dir==NW){
		auto x=std::lower_bound(right[a-b+m+1].begin(),right[a-b+m+1].end(),a)-1;
		if(count>1)ans+=a-(*x);
		bool bb1=set.count(std::make_pair(*x+1,(*x)-a+b)),bb2=set.count(std::make_pair(*x,(*x)-a+b+1));
		check1
		if((bb1&&bb2)||(!bb1&&!bb2)){
			if(!cando)cando=1,count=2,X=*x+1,Y=(*x)-a+b+1,ans=0;
			getans(*x+1,(*x)-a+b+1,SE,count);
		}
		else if(bb1&&!bb2)getans(*x,(*x)-a+b+1,NE,count);
		else if(!bb1&&bb2)getans(*x+1,(*x)-a+b,SW,count);
	}
	else if(dir==SE){
		auto x=std::upper_bound(right[a-b+m+1].begin(),right[a-b+m+1].end(),a);
		if(count>1)ans+=(*x)-a;
		bool bb1=set.count(std::make_pair(*x-1,(*x)-a+b)),bb2=set.count(std::make_pair(*x,(*x)-a+b-1));
		check1
		if((bb1&&bb2)||(!bb1&&!bb2)){
			if(!cando)cando=1,count=2,X=*x-1,Y=*x-a+b-1,ans=0;
			getans(*x-1,(*x)-a+b-1,NW,count);
		}
		else if(bb1&&!bb2)getans(*x,(*x)-a+b-1,SW,count);
		else if(!bb1&&bb2)getans(*x-1,(*x)-a+b,NE,count);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m+1;i++){
		left[i].push_back(0);
		right[m+1-i].push_back(0);
		left[i+n+1].push_back(n+1);
		right[m+1+n+1-i].push_back(n+1);
		set.insert(std::make_pair(0,i));
		set.insert(std::make_pair(n+1,i));
	}
	for(int i=0;i<=n+1;i++){
		left[i].push_back(i);
		right[m+1+i].push_back(i);
		left[i+m+1].push_back(i);
		right[i].push_back(i);
		set.insert(std::make_pair(i,0));
		set.insert(std::make_pair(i,m+1));
	}
	for(int i=1,x,y;i<=k;i++){
		scanf("%d%d",&x,&y);
		left[x+y].push_back(x);
		right[x-y+m+1].push_back(x);
		set.insert(std::make_pair(x,y));
	}
	for(int i=0;i<=n+m+2;i++)std::sort(left[i].begin(),left[i].end());
	for(int i=0;i<=n+m+2;i++)std::sort(right[i].begin(),right[i].end());
	scanf("%d%d",&X,&Y);
	ch1=get();
	ch2=get();
	getans(X,Y,((ch1=='S')?2:0)+((ch2=='W')?1:0)+1,0);
	printf("%I64d",(ans+1)>>1);
}
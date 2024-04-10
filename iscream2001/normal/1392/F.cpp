#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=1e6+10;
const int inf=1e9+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,d,mx;
LL h[N];
int q[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%I64d",&h[i]);
	int tp=1;q[1]=1;
	LL nd,ud;
	int x;
	for(int i=2;i<=n;++i){
		while(1){
			if(h[i]==h[q[tp]]){
				q[++tp]=i;
				break;
			}
			if(h[i]==h[q[tp]]+1){
				q[tp]=i;
				break;
			}
			if(tp>=2){
				nd=q[tp]-q[tp-1];
				//cout<<"i "<<i<<" "<<nd<<endl;
				if(h[q[tp]]+1<=h[i]-nd){
					h[i]-=nd;
					h[q[tp]]++;
					q[tp-1]=q[tp];
					--tp;
				}
				else{
					ud=h[i]-(h[q[tp]]+1);
					q[tp-1]+=ud;
					q[tp]=i;
					h[i]=h[i]-ud;
					break;
				}
			}
			else {
				nd=q[tp];
				if(h[q[tp]]+1<=h[i]-nd){
					ud=(h[i]-h[q[tp]])/(LL)(nd+1);
					h[q[tp]]+=ud;
					h[i]-=ud*nd;
				}
				else{
					ud=h[i]-(h[q[tp]]+1);
					q[tp]=ud;
					q[tp+1]=i;
					++tp;
					h[i]=h[i]-ud;
					break;
				}
			}
		}
		//cout<<tp<<" "<<q[tp]<<" "<<h[i]<<endl;
	}
	--tp;
	for(int i=n-1;i>=1;--i){
		h[i]=h[i+1]-1;
		if(tp>0&&q[tp]==i){
			++h[i];
			--tp;
		}
	}
	for(int i=1;i<=n;++i){
		print(h[i]);putchar(' ');
	}
	puts("");
	return 0;
}
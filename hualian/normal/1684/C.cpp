#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
vector<int> a[N];
int n,m;
signed main(){
	int T=read();while(T--){
		n=read(),m=read();
		int fl=0,fr=-1,to=-1;
		For(i,1,n){
			a[i].resize(m+1);
			int mx=0,pos=-1;
			For(j,1,m){
				a[i][j]=read();
				if(a[i][j]>mx)mx=a[i][j],pos=j;
				if(a[i][j]<mx){
					fr=pos,to=j,fl=1;
				}
			}
		}if(!fl)puts("1 1");
		else{
			int no=0;
			For(i,1,n){
				swap(a[i][fr],a[i][to]);
				For(j,2,m)if(a[i][j]<a[i][j-1]){
					no=1;
				}
			}if(no)puts("-1");
			else cout<<fr<<" "<<to<<endl;
		}
	}
	return 0;
}
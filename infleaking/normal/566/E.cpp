#include<bits/stdc++.h>
using namespace std;
const int N=1010;
bitset<N> a[N];
int mrk[N][N],n,cnt[N],ty[N],tag[N],rem;
vector<int> w[N];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int k,x;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			scanf("%d",&x);
			a[i][x]=1;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			bitset<N> z=a[i]&a[j];
			if (z.count()==2){
				int x,y;
				for (int k=1;k<=n;k++)
					if (z[k])y=x,x=k;
				if (!mrk[x][y]){
					w[x].push_back(y);
					w[y].push_back(x);
					mrk[x][y]=mrk[y][x]=1;
					rem++;
//					cerr<<x<<' '<<y<<endl;
				}
				ty[x]=ty[y]=1;
			}
		}
	if (rem==0){
		for (int i=2;i<=n;i++)printf("1 %d\n",i);
		return 0;
	}
	if (rem==1){
		int x,y;
		for (int k=1;k<=n;k++)
			if (ty[k])y=x,x=k;
		for (int i=1;i<=n;i++){
			if (a[i].count()!=n){
				for (int j=1;j<=n;j++)
					if (!a[i][j]){
						printf("%d %d\n",x,j);
						ty[j]=1;
					}
				break;
			}
		}
		for (int i=1;i<=n;i++)
			if (!ty[i])printf("%d %d\n",y,i);
		cout<<x<<' '<<y<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (!ty[i]){
			bitset<N> z;
			int tag1=0;
			for (int i=1;i<=n;i++)z[i]=1;
			for (int j=1;j<=n;j++)
				if (a[j][i])z&=a[j];
			int c1=0;
			for (int j=1;j<=n;j++)
				if (z[j]&&ty[j])c1++;
			for (int y=1;y<=n;y++){
				if (z[y]&ty[y]){
					if (w[y].size()!=c1-1)continue;
					int can=1;
					for (auto j:w[y])
						if (!z[j]){
							can=0;
							break;
						}
					if (can){
						assert(tag1==0);
						mrk[i][y]=mrk[y][i]=1;
						tag1=1;
//						break;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<i;j++){
		if (mrk[i][j])
			printf("%d %d\n",i,j);
	}
}
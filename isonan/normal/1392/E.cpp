#include <cstdio>
#include <vector>

int n,q;
long long a[51][51],k,_mul[51];
std::vector<std::pair<int,int> >vec[51],ans;
int main(){
	scanf("%d",&n);
	_mul[0]=_mul[1]=1;
	for(int i=2;i<=(n<<1);i++)_mul[i]=1ll*_mul[i-1]*i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vec[i+j].push_back(std::make_pair(i,j));
	long long Mul=1;
	for(int i=2;i<=n<<1;i++){
		for(int j=0;j<vec[i].size();j++)
			a[vec[i][j].first][vec[i][j].second]=(j&1)?Mul:0;
		Mul*=2;
	}
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=n;j++)
			printf("%lld ",a[i][j]);
	fflush(stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%lld",&k);
		ans.clear();
		int ex=n,ey=n;
		long long tem=Mul/2;
		for(int j=(n<<1)-1;j>1;j--){
			tem/=2;
			ans.push_back(std::make_pair(ex,ey));
			if(ex>1&&(a[ex-1][ey]!=0)==((k&tem)!=0))--ex;
			else --ey;
			k%=tem;
		}
		ans.push_back(std::make_pair(1,1));
		for(int i=ans.size()-1;~i;i--)printf("%d %d\n",ans[i].first,ans[i].second);
		fflush(stdout);
	}
}
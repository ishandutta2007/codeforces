#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

int n,k;
int main(){
    scanf("%d%d",&n,&k);
    printf("%d\n",k*(6*n-1));
    int p=1;
    FOR(i,1,n){
        printf("%d %d %d ",k*p,k*(p+2),k*(p+4));
        if ((p+4)%3==0) printf("%d\n",k*(p+3));else printf("%d ",k*(p+1));ENDL;
        p+=6;
    }
}
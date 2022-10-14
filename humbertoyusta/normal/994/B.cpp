#include<bits/stdc++.h>
#define maxn 100005
#define db(x) cerr<<#x<<": "<<(x)<<'\n'
using namespace std;

struct tres{
long long num,cos,pos;
bool operator < ( const tres & other ){
    return num < other.num;
}
};

tres a[maxn];
long long n,m,k,t[15];
long long ans[maxn];
priority_queue<long long> q;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /// freopen("a.in","r",stdin);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i].num;
        a[i].pos = i;
    }

    for(int i=1; i<=n; i++)
        cin >> a[i].cos;

    sort(a+1,a+n+1);

    for(int z=1; z<=n; z++){
        long long sum=0; int cont = 0;
        for(int i=1; i<=k; i++){
            if(q.empty()) break;
            t[i]=q.top();
            q.pop();
            sum+=t[i];
            cont++;
        }
        for(int i=1; i<=cont; i++){
            q.push(t[i]);
        }
        q.push(a[z].cos);
        sum+=a[z].cos;

        ans[a[z].pos]=sum;

    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<' ';

return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define DIM 5007
#define INF 10E10
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n,a,b,c,d,a1,b1,c1,d1,a2,b2,c2,d2;
ll A[DIM][2];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    char ch;
    for (int i = 1;i<=n;i++){
        cin>>ch;
        A[i][0]=ch-'0';
    }
    for (int i = 1;i<=n;i++){
        cin>>ch;
        A[i][1]=ch-'0';
    }
    for (int i = 1;i<=n;i++){
        if (A[i][0]==1 && A[i][1]==1)d++;
        if (A[i][0]==1 && A[i][1]==0)b++;
        if (A[i][0]==0 && A[i][1]==1)c++;
        if (A[i][0]==0 && A[i][1]==0)a++;
    }
    ll r;
    for (int i = 0;i<=n/2;i++){
        for (int j = 0;j<=n/2;j++){
            b1 = i; c1 = j;
            r = b1+c1-c-d;
            if (r%2==1)continue;
            d1 = (-1)*r/2;
            a1 = n/2-b1-c1-d1;
            a2 = a-a1;
            b2 = b-b1;
            c2 = c-c1;
            d2 = d-d1;
            if (a1>=0 && a2>=0 && b1>=0 && b2>=0 && c1>=0 && c2>=0 && d1>=0 && d2>=0 && b1+d1==c2+d2){
                for (int i = 1;i<=n;i++){
                    if (A[i][0]==1 && A[i][1]==1 && d1>0){
                        d1--;
                        cout<<i<<' ';
                    }
                    if (A[i][0]==1 && A[i][1]==0 && b1>0){
                        cout<<i<<' ';
                        b1--;
                    }
                    if (A[i][0]==0 && A[i][1]==1 && c1>0){
                        cout<<i<<' ';
                        c1--;
                    }
                    if (A[i][0]==0 && A[i][1]==0 && a1>0){
                        cout<<i<<' ';
                        a1--;
                    }
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}
// a1+b1+c1+d1 = n/2;
// b1+d1==c2+d2;
// b1+d1==c-c1+d-d1
// b1+d1+c1+d1=c+d
// b1+c1+2*d1=c+d
// b1+c1-c-d=-2*d1
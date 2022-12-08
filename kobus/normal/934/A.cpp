#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 212
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX 21234


int a[MAX];
int b[MAX];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    
    int an,bn;
    cin>>an>>bn;
    for(int i=0;i<an;i++)cin>>a[i];
    for(int i=0;i<bn;i++)cin>>b[i];
    int max=-INF;
    int anomax;
    for(int i=0;i<an;i++){
        for(int j=0;j<bn;j++){
            if(a[i]*b[j]>max){
                max=a[i]*b[j];
                anomax=i;
            }
        }
    }
    max=-INF;
    for(int i=0;i<an;i++){
        for(int j=0;j<bn;j++){
            if(i!=anomax && a[i]*b[j]>max){
                max=a[i]*b[j];
            }
        }
    }
    cout<<max<<endl;

    return 0;

}
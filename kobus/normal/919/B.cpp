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
#define MOD 999999599
#define cte 10002
#define MAX 21234


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    for(int i=0;i<112345678;i++){
        int num=i;
        int soma=0;
        while(num!=0){
            soma+=num%10;
            num=num/10;
        }
        if(soma==10)n--;
        if(n==0){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;

}
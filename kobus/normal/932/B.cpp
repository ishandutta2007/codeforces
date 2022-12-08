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
#define MAX 21234

int val[1123456];
int v[1123456][10];

int g(int n){
    int ori=n;
    if(n<10)return n;
    int num=1;
    while(n!=0){
        //cout<<n<<endl;
        if((n%10)!=0)num*=(n%10);
        n=n/10;
    }
    return val[num];
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    for(int i=0;i<1123456;i++)val[i]=g(i);
    //cout<<"AA"<<endl;
    for(int i=1;i<1123456;i++){
        for(int j=0;j<10;j++)v[i][j]=v[i-1][j];
        v[i][val[i]]++;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int com,fim,k;
        cin>>com>>fim>>k;
        cout<<v[fim][k]-v[com-1][k]<<endl;
    }
    

    return 0;

}
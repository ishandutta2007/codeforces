#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;
int pp[10000003];
int p[10000003];
int f(int a){
    int q = p[a];
    while(a%(q*p[a])==0)q*=p[a];
    return q;
}
int main(){
    for(int i = 2; i < 10000003; i++){
        if(pp[i])continue;
        p[i] = i; pp[i] = i;
        for(int j = 2*i; j < 10000003; j+=i){
            if(pp[j]==0)pp[j]=i;
            p[j]=i;
        }
    //    cout << "ses"<<endl;
    }
    //cout << "sos"<<endl;
    cin >> N;
    vi a(N);

    for(int i =0; i < N; i++ )scanf("%d", &a[i]);
    for(auto x: a){
        if(pp[x]==p[x])printf("-1 ");
        else printf("%d ", f(x));
    }

    cout << "\n";

    for(auto x: a){
        if(pp[x]==p[x])printf("-1 ");
        else printf("%d ", x/f(x));
    }

    return 0;
}
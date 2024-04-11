#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 3241618756


int par[212345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    k=n-k;
    stack<int> st;
    int aux=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            par[i]=aux;
            st.push(aux);
            aux++;
        }
        else{
            par[i]=st.top();
            st.pop();
        }
    }
    for(int i=0;i<n;i++){
        if(par[i]>=k/2)cout<<s[i];;
    }
    cout<<endl;

    return 0;
}
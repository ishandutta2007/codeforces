#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;
typedef unsigned long long ull;

//#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
bool ask(int a,int b,int c){
    cout<<"? "<<a<<' '<<b<<' '<<c<<endl;
    bool ret;
    cin>>ret;
    return ret;
}
bool ask(vector<int> &V){

    cout<<"? ";
    assert(V.size()==3);
    for(int to:V)
        cout<<to<<' ';
    cout<<endl;
    bool ret;
    cin>>ret;
    return ret;
}
const int N = 1e4+7;
bool col[N];
void solve(pair<int,int> &df,int pos,int cl){
    bool ret;
    if (cl==0){
        ret = ask(df.second,pos,pos+1);
    }
    else{
        ret = ask(df.first,pos,pos+1);
    }
    if (ret==cl){
        col[pos] = col[pos+1] = cl;
        col[pos+2] = ask(df.first,df.second,pos+2);
    }
    else{
        col[pos+2] = cl;
        col[pos] = ask(df.first,df.second,pos);
        col[pos+1] = col[pos]^1;
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        col[i] = 0;
    vector<int> st[2];
    for(int i = 1;i<=n;i+=3){
        bool ret = ask(i,i+1,i+2);
        st[ret].push_back(i);
    }
    assert(!st[0].empty() && !st[1].empty());
    int a = st[0].back(),b = st[1].back();
    st[0].pop_back(); st[1].pop_back();
    vector<int> A = {a,a+1,a+2},B = {b,b+1,b+2};
    int FL = 0;
    pair<int,int> df;
    for(int i = 0;i<2;++i){
        int other = A[i];
        bool flag = 0;
        int ps = 0;
        for(int pos:B){
            vector<int> to_ask = {other};
            for(int cur:B){
                if (cur!=pos)
                    to_ask.push_back(cur);
            }
            bool ret = ask(to_ask);
            if (ret==0)
                flag = 1,ps = pos;
        }
        if (flag){
            FL = 1;
            df = {other,ps};
            break;
        }
    }
    if (!FL){
        col[B[0]] = col[B[1]] = col[B[2]] = 1;
        df.second = B[0];
        if (ask(B[0],A[0],A[1])==0) {
            df.first = A[0];
            col[A[0]] = col[A[1]] = 0;
            col[A[2]] = ask(df.first,df.second,A[2]);
        }
        else if (ask(B[0],A[1],A[2])==0) {
            df.first = A[1];
            col[A[1]] = col[A[2]] = 0;
            col[A[0]] = ask(df.first,df.second,A[0]);
        }
        else{
            df.first = A[0];
            col[A[0]] = col[A[2]] = 0;
            col[A[1]] = 1;
        }
        col[df.second] = 1;

    }
    else{
        col[df.first] = 0;
        col[df.second] = 1;
        for(int to:A){
            if (to==df.first || to==df.second)
                continue;
            col[to] = ask(df.first,df.second,to);
        }
        for(int to:B){
            if (to==df.first || to==df.second)
                continue;
            col[to] = ask(df.first,df.second,to);
        }

    }
    col[df.first] = 0,col[df.second] = 1;
    while(!st[0].empty()){
        solve(df,st[0].back(),0);
        st[0].pop_back();
    }
    while(!st[1].empty()){
        solve(df,st[1].back(),1);
        st[1].pop_back();
    }
    vector<int> ans;
    for(int i = 1;i<=n;++i)
        if (!col[i])
            ans.push_back(i);
    cout<<"! "<<ans.size()<<' ';
    for(int to:ans)
        cout<<to<<' ';
    cout<<endl;
}
signed main(){
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}
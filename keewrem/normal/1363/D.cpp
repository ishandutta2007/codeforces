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


vector<vector<int>> v;

int query(int a, int b){
    int ses = 0;
    for(int i = a; i < b; i++)ses+=v[i].size();
    cout <<"? "<< ses;
    for(int i = a; i < b; i++)for(auto x: v[i])cout<<" " << x;
    cout << endl;
    cout.flush();
    cin >> ses;
    return ses;
}

int queryb(int a, int b, int c){
    int ses = 0;
    for(int i = a; i < b; i++)if(i!=c)ses+=v[i].size();
    cout <<"? "<< ses;
    for(int i = a; i < b; i++)if(i!=c)for(auto x: v[i])cout<<" " << x;
    cout << endl;
    cout.flush();
    cin >> ses;
    return ses;
}
bool tkn[10000];

int T; string s;
int N,K,a,b;
int ans[1001];
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        v.clear();
        v.resize(K);
        for(int i =1;i <= N; i++)tkn[i] = 0;
        for(int i = 0; i < K; i++){
            cin >> a;
            v[i].resize(a);
        for(int j  = 0; j < a; j++){
                cin >> b;
                v[i][j]=b;
            }
        }
        int f = 0;

            int l = K,mid = (f+l)/2;
            int lw, up, ls;
        if(K!=1){
            lw = query(f,mid); up = query(mid,l);
            if(up < lw){
                ls = lw; l = mid;
            }else{
                ls = up; f = mid;
            }
            while(f+1<l){
                mid = (f+l)/2;
                if(query(f,mid) == ls)l = mid;
                else f = mid;
            }
        }
        for(int i = 0; i < K; i++)if(i!=f)ans[i] = ls;
    //    cout << "LW"<< f << "\n";
        ans[f] = 0;
        for(auto x: v[f])tkn[x] =1;
        if(v[f].size()!=N){
            cout << "? " << N-v[f].size();
            for(int i = 1; i <= N; i++)if(!tkn[i])cout << " "<< i;
            cout << endl; cout.flush();
            int mm; cin >> mm;

            for(int i = 0; i < K; i++)ans[i] = max(ans[i],mm);
        }

        cout << "!";
        for(int i = 0; i < K; i++)cout << " " << ans[i];
        cout << endl;
        cout.flush();
        cin >> s;
        if (s == "Incorrect")return 0;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
inline void Routine() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}
int main() {
    Routine();
    int n,b,c,ans=0,ansi,ii=0,uu=0,x=0,y=0,u,co=1;
    string s,s1;
    char cu;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];

    }
    vector<int>o;
    o.push_back(a[0]);
    for(int i=1;i<n;i++){
        if (a[i]==a[i-1]+1){
            co++;
            o.push_back(a[i]);
        }
        else{

            if (o[0]==1){
                co++;
            }
            if (o[o.size()-1]==1000){
                co++;
            }
            ans=max(ans,co-2);
            int t=o.size();
            for(int p=0;p<t;p++){
                o.pop_back();
            }
            co=1;


        }

    }
    if (o[0]==1){
                co++;
            }
            if (o[o.size()-1]==1000){
                co++;
            }
            ans=max(ans,co-2);
            int t=o.size();
            for(int p=0;p<t;p++){
                o.pop_back();
            }
            co=1;
    cout << ans;











    return 0;
}
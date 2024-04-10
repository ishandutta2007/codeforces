 #include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;

string s,t,rs,rt;
vector<int>ans;

int main() {
    cin >> n >> s >> t;

    rs = s;
    sort(rs.begin(), rs.end());

    rt = t;
    sort(rt.begin(), rt.end());

    if(rs != rt)
        return cout<<-1,0;

    for(int i=0; i<n; i++){
        if(t[i] == s[i])
            continue;
        for(int j=i+1; j<n; j++){
            if(t[i] == s[j]){
                for(int k=j; k>i; k--)
                    swap(s[k],s[k-1]),ans.push_back(k);
                break;
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto nx:ans)cout<<nx<<' ';

    return 0;
}
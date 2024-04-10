// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int m;
    cin>>m;
    vector<vector<int>>cnt(n);
    for(int i=0;i<n;++i){
        cnt[i].resize(26);
        ++cnt[i][s[i]-'a'];
        if(i>0){
            for(int j=0;j<26;++j){
                cnt[i][j]+=cnt[i-1][j];
            }
        }
    }
    for(;m--;){
        string t;
        cin>>t;
        vector<int>c(26);
        int m=t.length();
        for(int i=0;i<m;++i){
            ++c[t[i]-'a'];
        }
        int l=1,r=n;
        for(;l<r;){
            int mid=(l+r)>>1;
            bool flag=true;
            for(int i=0;i<26;++i){
                if(cnt[mid-1][i]<c[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}
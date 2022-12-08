#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF LLONG_MAX
#define int long long

set<int> occ[31];
 
int32_t main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string s2;
        int uni=0;
        for(int i=0;i<s.size();i++){
            if(occ[s[i]-'a'].size()==0)uni++;
            occ[s[i]-'a'].insert(i);
        }
        while(uni--){
            //cout<<uni<<endl;
            int deu=0;
            for(int i=25;i>=0;i--){
                //cout<<"i "<<i<<endl;
                if(occ[i].size()>0){
                    int com=*occ[i].begin();
                    //cout<<i<<" "<<com<<endl;
                    bool ruim=0;
                    for(int j=0;j<26;j++){
                        if(occ[j].size()>0 && (*occ[j].rbegin())<com){
                            ruim=1;
                            break;
                        }
                    }
                    if(ruim==0){
                        deu=i;
                        break;
                    }
                }
            }
            //cout<<deu<<endl;
            s2.pb((char)('a'+deu));
            int com=*occ[deu].begin();
            occ[deu].clear();
            for(int i=25;i>=0;i--){
                while(occ[i].size()>0 && *occ[i].begin()<com){
                    occ[i].erase(*occ[i].begin());
                }
            }
        }
        cout<<s2<<endl;


    }

    return 0;
}
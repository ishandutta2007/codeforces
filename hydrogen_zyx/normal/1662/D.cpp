///
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f,N=205;

char s[2][N];
int c[2][3];
vector<int>v[2];

int main(){
    #ifdef ONLINE_JUDGE
        //std::ios::sync_with_stdio(false);
    #else
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--){
        v[0].clear();
        v[1].clear();
        memset(c,0,sizeof(c));
        scanf(" %s %s",s[0],s[1]);
        for(int i=0;i<2;i++){
            int len=strlen(s[i]);
            for(int j=0;j<len;j++){
                c[i][s[i][j]-'A']^=1;
                if(s[i][j]!='B'){
                    if(v[i].size()&&v[i].back()==s[i][j]){
                        v[i].pop_back();
                    }
                    else v[i].push_back(s[i][j]);
                }
            }
        }
        bool f=1;
        for(int i=0;i<3;i++)if(c[0][i]!=c[1][i])f=0;
        if(v[0].size()!=v[1].size())f=0;
        for(int i=0;i<min(v[0].size(),v[1].size());i++){
            if(v[0][i]!=v[1][i])f=0;
        }
        printf(f?"YES\n":"NO\n");
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
const int MAXN = 1E6+10;
vector<PIII> E[2000];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        E[y/1000].push_back(PIII(PII(x,y),i));
    }
    int flag = 0;
    for(int i = 0; i < 1000; i++){
        if (E[i].size()){
            sort(E[i].begin(), E[i].end());
            if (flag)
                for(int j = 0; j < E[i].size(); j++)
                    printf("%d ", E[i][j].second);
            else
                for(int j = E[i].size()-1; j >= 0; j--)
                    printf("%d ", E[i][j].second);
            flag = 1 - flag;
        }
    }
    puts("");
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

vector<PII> E;

int main(){
    int n,d;
    cin>>n>>d;
    for(int i = 1; i <= n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        E.push_back(PII(x,y));
    }
    sort(E.begin(), E.end());
    long long ans = 0;
    int j = n - 1;
    long long now = 0;
    for(int i = n - 1; i >= 0; i--){
        while( j > i && E[i].first + d <= E[j].first ){
            now -= E[j].second;
            j--;
        }
        now += E[i].second; 
        if (now > ans)
            ans = now;
    }
    printf("%lld\n",ans);
    return 0;
}
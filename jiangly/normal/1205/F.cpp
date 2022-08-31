#include<bits/stdc++.h>
using namespace std;
const int MAX_N=105;
vector<int> ans[MAX_N][MAX_N*MAX_N];
vector<pair<int,int>> que;
void bfs(int p){
    if(p==que.size()){
        return;
    }
    auto [a1,b1]=que[p];
    for(int i=1;i<=p;++i){
        auto [a2,b2]=que[i];
        int a3=a1+a2-1;
        int b3=b1+b2-1;
        if(a3<=100&&ans[a3][b3].empty()){
            for(int x:ans[a2][b2]){
                ans[a3][b3].push_back(ans[a1][b1].front()+x-1);
            }
            for(int x:ans[a1][b1]){
                if(x!=ans[a1][b1].front()){
                    ans[a3][b3].push_back(x<ans[a1][b1].front()?x:x+a2);
                }
            }
            int x=min(ans[a3][b3][a2-1],ans[a3][b3][a2]);
            int y=max(ans[a3][b3][a2-1],ans[a3][b3][a2]);
            if(ans[a3][b3].front()<x||ans[a3][b3].front()>y){
                reverse(ans[a3][b3].begin(),ans[a3][b3].begin()+a2);
            }
            que.emplace_back(a3,b3);
        }
    }
    bfs(p+1);
}
int main(){
    for(int i=1;i<=100;++i){
        for(int j=1;j<=i;++j){
            ans[i][i*(i+1)/2].push_back(j);
        }
    }
    for(int i=4;i<=100;++i){
        for(int j=1;j<=i;++j){
            ans[i][i+1].push_back((j&1)?(j+i+1)/2:j/2);
        }
        if(i&1){
            swap(ans[i][i+1][i-3],ans[i][i+1][i-1]);
        }
    }
    for(int a=2;a<=100;++a){
        for(int b=a+1;b<=a*(a+1)/2;++b){
            if(ans[a][b].empty()){
                bool ok=false;
                for(int a1=4;a1<=a&&!ok;++a1){
                    int b1=a1+1;
                    int a2=a-a1+1;
                    int b2=b-b1+1;
                    if(!ans[a2][b2].empty()){
                        for(int x:ans[a2][b2]){
                            ans[a][b].push_back(ans[a1][b1].front()+x-1);
                        }
                        for(int x:ans[a1][b1]){
                            if(x!=ans[a1][b1].front()){
                                ans[a][b].push_back(x<ans[a1][b1].front()?x:x+a2-1);
                            }
                        }
                        int x=min(ans[a][b][a2-1],ans[a][b][a2]);
                        int y=max(ans[a][b][a2-1],ans[a][b][a2]);
                        if(ans[a][b].front()<x||ans[a][b].front()>y){
                            reverse(ans[a][b].begin(),ans[a][b].begin()+a2);
                        }
                        ok=true;
                    }
                }
                for(int a1=2;a1<=a&&a1*(a1+1)/2<=b&&!ok;++a1){
                    int b1=a1*(a1+1)/2;
                    int a2=a-a1+1;
                    int b2=b-b1+1;
                    if(!ans[a2][b2].empty()){
                        for(int x:ans[a2][b2]){
                            ans[a][b].push_back(ans[a1][b1].front()+x-1);
                        }
                        for(int x:ans[a1][b1]){
                            if(x!=ans[a1][b1].front()){
                                ans[a][b].push_back(x<ans[a1][b1].front()?x:x+a2-1);
                            }
                        }
                        int x=min(ans[a][b][a2-1],ans[a][b][a2]);
                        int y=max(ans[a][b][a2-1],ans[a][b][a2]);
                        if(ans[a][b].front()<x||ans[a][b].front()>y){
                            reverse(ans[a][b].begin(),ans[a][b].begin()+a2);
                        }
                        ok=true;
                    }
                }
            }
        }
    }
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        if(ans[a][b].empty()){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int x:ans[a][b]){
                cout<<x<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
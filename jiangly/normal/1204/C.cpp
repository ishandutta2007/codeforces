#include<bits/stdc++.h>
using namespace std;
constexpr int INF=1e9;
class Solver{
private:
    static constexpr int MAX_N=100;
    static constexpr int MAX_M=1e6;
    int n,m;
    int p[MAX_M];
    int dis[MAX_N][MAX_N];
    int dp[MAX_M];
    int from[MAX_M];
    bool used[MAX_M];
public:
    void solve(){
        cin>>n;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            for(int j=0;j<n;++j){
                if(s[j]=='1'){
                    dis[i][j]=1;
                }else{
                    dis[i][j]=INF;
                }
            }
            dis[i][i]=0;
        }
        cin>>m;
        for(int i=0;i<m;++i){
            cin>>p[i];
            --p[i];
        }
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        dp[0]=1;
        from[0]=-1;
        deque<int> que;
        que.push_back(0);
        for(int i=1,j=0;i<m;++i){
            while(dis[p[j]][p[i]]<i-j){
                if(!que.empty()&&que.front()==j){
                    que.pop_front();
                }
                ++j;
            }
            from[i]=que.front();
            dp[i]=dp[que.front()]+1;
            while(!que.empty()&&dp[i]<=dp[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }
        int cnt=0;
        for(int i=m-1;i!=-1;i=from[i]){
            used[i]=true;
            ++cnt;
        }
        cout<<cnt<<endl;
        for(int i=0;i<m;++i){
            if(used[i]){
                cout<<p[i]+1<<' ';
            }
        }
        cout<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solver().solve();
    return 0;
}
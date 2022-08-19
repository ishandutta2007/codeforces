#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int MAX_N=5e3;
    bitset<MAX_N> cross[MAX_N];
    int n;
    int cnth=0;
    int cntv=0;
    class Seg{
    public:
        int x1;
        int x2;
        int y;
        Seg(int x1=0,int x2=0,int y=0):x1(x1),x2(x2),y(y){}
    };
    Seg ver[MAX_N];
    Seg hor[MAX_N];
public:
    void solve(){
        cin>>n;
        for(int i=0;i<n;++i){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(y1==y2){
                if(x1>x2){
                    swap(x1,x2);
                }
                hor[cnth++]={x1,x2,y1};
            }else{
                if(y1>y2){
                    swap(y1,y2);
                }
                ver[cntv++]={y1,y2,x1};
            }
        }
        if(cnth>cntv){
            swap(cnth,cntv);
            swap(hor,ver);
        }
        for(int i=0;i<cnth;++i){
            for(int j=0;j<cntv;++j){
                if(hor[i].y>=ver[j].x1&&hor[i].y<=ver[j].x2&&ver[j].y>=hor[i].x1&&ver[j].y<=hor[i].x2){
                    cross[i][j]=1;
                }
            }
        }
        LL ans=0;
        for(int i=0;i<cnth;++i){
            for(int j=0;j<i;++j){
                int x=(cross[i]&cross[j]).count();
                ans+=1ll*x*(x-1)/2;
            }
        }
        cout<<ans<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}
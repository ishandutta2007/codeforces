#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
int readInt(){
    int x=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
void solve_single_test(int test_id=1){
    const vector<pair<int,int>> moves={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
    int n=readInt(); 
    int m=readInt();
    int white_x=readInt()-1;
    int white_y=readInt()-1;
    int black_x=readInt()-1;
    int black_y=readInt()-1;
    vector<vector<int>> dis_white_goal(n,vector<int>(m,-1));
    vector<vector<int>> dis_black_goal(n,vector<int>(m,-1));
    vector<vector<vector<pair<int,int>>>> moves_from(n,vector<vector<pair<int,int>>>(m));
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){
            for(auto [dx,dy]:moves){
                int to_x=x+dx;
                int to_y=y+dy;
                if(to_x>=0&&to_x<n&&to_y>=0&&to_y<m){
                    moves_from[x][y].emplace_back(to_x,to_y);
                }
            }
        }
    }
    queue<pair<int,int>> que;
    dis_white_goal[n/2-1][m/2-1]=0;
    que.emplace(n/2-1,m/2-1);
    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop();
        for(auto [to_x,to_y]:moves_from[x][y]){
            if(dis_white_goal[to_x][to_y]==-1){
                dis_white_goal[to_x][to_y]=dis_white_goal[x][y]+1;
                que.emplace(to_x,to_y);
            }
        }
    }
    dis_black_goal[n/2][m/2-1]=0;
    que.emplace(n/2,m/2-1);
    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop();
        for(auto [to_x,to_y]:moves_from[x][y]){
            if(dis_black_goal[to_x][to_y]==-1){
                dis_black_goal[to_x][to_y]=dis_black_goal[x][y]+1;
                que.emplace(to_x,to_y);
            }
        }
    }
    if(dis_white_goal[white_x][white_y]+1<=dis_white_goal[black_x][black_y]&&dis_white_goal[white_x][white_y]<=dis_black_goal[black_x][black_y]){
        puts("WHITE");
        fflush(stdout);
        while(white_x!=n/2-1||white_y!=m/2-1){
            for(auto [to_x,to_y]:moves_from[white_x][white_y]){
                if(dis_white_goal[to_x][to_y]<dis_white_goal[white_x][white_y]){
                    white_x=to_x;
                    white_y=to_y;
                    printf("%d %d\n",white_x+1,white_y+1);
                    fflush(stdout);
                    if(white_x==black_x&&white_y==black_y){
                        return;
                    }
                    if(white_x!=n/2-1||white_y!=m/2-1){
                        black_x=readInt()-1;
                        black_y=readInt()-1;
                    }
                    break;
                }
            }
        }
    }else if(dis_black_goal[black_x][black_y]+2<=dis_black_goal[white_x][white_y]&&dis_black_goal[black_x][black_y]+1<=dis_white_goal[white_x][white_y]){
        puts("BLACK");
        fflush(stdout);
        white_x=readInt()-1;
        white_y=readInt()-1;
        while(black_x!=n/2||black_y!=m/2-1){
            for(auto [to_x,to_y]:moves_from[black_x][black_y]){
                if(dis_black_goal[to_x][to_y]<dis_black_goal[black_x][black_y]){
                    black_x=to_x;
                    black_y=to_y;
                    printf("%d %d\n",black_x+1,black_y+1);
                    fflush(stdout);
                    if(white_x==black_x&&white_y==black_y){
                        return;
                    }
                    if(black_x!=n/2||black_y!=m/2-1){
                        white_x=readInt()-1;
                        white_y=readInt()-1;
                    }
                    break;
                }
            }
        }
    }else if((white_x+white_y)%2!=(black_x+black_y)%2){
        puts("WHITE");
        fflush(stdout);
        if(dis_white_goal[white_x][white_y]<=dis_black_goal[black_x][black_y]){
            while(white_x!=n/2-1||white_y!=m/2-1){
                for(auto [to_x,to_y]:moves_from[white_x][white_y]){
                    if(dis_white_goal[to_x][to_y]<dis_white_goal[white_x][white_y]){
                        white_x=to_x;
                        white_y=to_y;
                        printf("%d %d\n",white_x+1,white_y+1);
                        fflush(stdout);
                        if(white_x==black_x&&white_y==black_y){
                            return;
                        }
                        if(white_x!=n/2-1||white_y!=m/2-1){
                            black_x=readInt()-1;
                            black_y=readInt()-1;
                        }
                        break;
                    }
                }
            }
        }else{
            while(white_x!=n/2||white_y!=m/2-1){
                for(auto [to_x,to_y]:moves_from[white_x][white_y]){
                    if(dis_black_goal[to_x][to_y]<dis_black_goal[white_x][white_y]){
                        white_x=to_x;
                        white_y=to_y;
                        printf("%d %d\n",white_x+1,white_y+1);
                        fflush(stdout);
                        if(white_x==black_x&&white_y==black_y){
                            return;
                        }
                        black_x=readInt()-1;
                        black_y=readInt()-1;
                        break;
                    }
                }
            }
            if(dis_black_goal[black_x][black_y]==1){
                printf("%d %d\n",black_x+1,black_y+1);
                fflush(stdout);
            }else{
                while(white_x!=n/2-1||white_y!=m/2-1){
                    for(auto [to_x,to_y]:moves_from[white_x][white_y]){
                        if(dis_white_goal[to_x][to_y]<dis_white_goal[white_x][white_y]){
                            white_x=to_x;
                            white_y=to_y;
                            printf("%d %d\n",white_x+1,white_y+1);
                            fflush(stdout);
                            if(white_x==black_x&&white_y==black_y){
                                return;
                            }
                            if(white_x!=n/2-1||white_y!=m/2-1){
                                black_x=readInt()-1;
                                black_y=readInt()-1;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }else{
        puts("BLACK");
        fflush(stdout);
        white_x=readInt()-1;
        white_y=readInt()-1;
        if(dis_black_goal[black_x][black_y]<=dis_white_goal[white_x][white_y]){
            while(black_x!=n/2||black_y!=m/2-1){
                for(auto [to_x,to_y]:moves_from[black_x][black_y]){
                    if(dis_black_goal[to_x][to_y]<dis_black_goal[black_x][black_y]){
                        black_x=to_x;
                        black_y=to_y;
                        printf("%d %d\n",black_x+1,black_y+1);
                        fflush(stdout);
                        if(white_x==black_x&&white_y==black_y){
                            return;
                        }
                        if(black_x!=n/2||black_y!=m/2-1){
                            white_x=readInt()-1;
                            white_y=readInt()-1;
                        }
                        break;
                    }
                }
            }
        }else{
            while(black_x!=n/2-1||black_y!=m/2-1){
                for(auto [to_x,to_y]:moves_from[black_x][black_y]){
                    if(dis_white_goal[to_x][to_y]<dis_white_goal[black_x][black_y]){
                        black_x=to_x;
                        black_y=to_y;
                        printf("%d %d\n",black_x+1,black_y+1);
                        fflush(stdout);
                        if(white_x==black_x&&white_y==black_y){
                            return;
                        }
                        white_x=readInt()-1;
                        white_y=readInt()-1;
                        break;
                    }
                }
            }
            if(dis_white_goal[white_x][white_y]==1){
                printf("%d %d\n",white_x+1,white_y+1);
                fflush(stdout);
            }else{
                while(black_x!=n/2||black_y!=m/2-1){
                    for(auto [to_x,to_y]:moves_from[black_x][black_y]){
                        if(dis_black_goal[to_x][to_y]<dis_black_goal[black_x][black_y]){
                            black_x=to_x;
                            black_y=to_y;
                            printf("%d %d\n",black_x+1,black_y+1);
                            fflush(stdout);
                            if(white_x==black_x&&white_y==black_y){
                                return;
                            }
                            if(black_x!=n/2||black_y!=m/2-1){
                                white_x=readInt()-1;
                                white_y=readInt()-1;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
void solve_multiple_tests(){
    int n_tests;
    n_tests=readInt();
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}
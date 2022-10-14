#include<bits/stdc++.h>
using namespace std;
int n,a,b;
char tab[1050][1050];
pair<int,int> itab[1050][1050];
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            scanf("%d %d", &itab[i][j].first,&itab[i][j].second);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == itab[i][j].first && j == itab[i][j].second)tab[i][j]='X';
            if(itab[i][j]== make_pair(-1,-1)&&itab[i][j+1]== make_pair(-1,-1)){
                tab[i][j]='R'; tab[i][j+1]='L';
            }
            if(itab[i][j]== make_pair(-1,-1)&&itab[i+1][j]== make_pair(-1,-1)){
                tab[i][j]='D'; tab[i+1][j]='U';
            }
        }
    }
    queue<pair<int,int>> q;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            if(tab[i][j]=='X'){
                q.push({i,j});
                while(!q.empty()){
                    a = q.front().first; b=q.front().second;
                    q.pop();
                    if(itab[a-1][b]==make_pair(i,j) && tab[a-1][b]<'A'){
                        tab[a-1][b]='D'; q.push({a-1,b});
                    }
                    if(itab[a+1][b]==make_pair(i,j) && tab[a+1][b]<'A'){
                        tab[a+1][b]='U'; q.push({a+1,b});
                    }
                    if(itab[a][b+1]==make_pair(i,j) && tab[a][b+1]<'A'){
                        tab[a][b+1]='L'; q.push({a,b+1});
                    }
                    if(itab[a][b-1]==make_pair(i,j) && tab[a][b-1]<'A'){
                        tab[a][b-1]='R'; q.push({a,b-1});
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)for(int j = 1; j <=n; j++)if(tab[i][j]<'A'){
        cout << "INVALID\n";
        return 0;
    }
    cout << "VALID\n";
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <=n; j++)
        cout << tab[i][j];
        cout << "\n";
    }
    return 0;
}
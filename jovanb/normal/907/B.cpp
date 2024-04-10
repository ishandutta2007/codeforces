#include <bits/stdc++.h>

using namespace std;
char mat[100][100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    char ch[50];
    int i,j,k,x,y,x1,y1;
    for(k=0;k<9;k++){
        for(i=0;i<3;i++){
        cin>>ch;
        for(j=0;j<3;j++)mat[k][i*3+j]=ch[j];
        }
    }
    cin>>x>>y;
    if(x%3==0)x1=9;
    else if(x%3==2)x1=6;
    else x1=3;
    if(y%3==0)y1=9;
    else if(y%3==2)y1=6;
    else y1=3;
    int mark=0;
    for(i=x1-3;i<x1;i++){
        for(j=y1-3;j<y1;j++){
            if(mat[i][j]=='.'){
                mat[i][j]='!';
                mark=1;
            }
        }
    }
    if(mark==0){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(mat[i][j]=='.')mat[i][j]='!';
            }
        }
    }
    for(i=0;i<9;i++){

        for(j=0;j<9;j++){
            cout<<mat[i][j];
            if(j%3==2){
                cout<<" ";
            }
        }
        if(i%3==2)cout<<endl;
        cout<<endl;
    }
    return 0;
}
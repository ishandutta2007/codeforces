#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n,m;
    cin>>n>>m;
    int ma[n][m];
    int ma2[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ma[i][j];
            ma2[i][j]=0;
        }
    }
    int num=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(ma[i][j]==1 && ma[i+1][j]==1 && ma[i][j+1] && ma[i+1][j+1]){
                num++;
                ma2[i][j]=1;
                ma2[i+1][j]=1;
                ma2[i][j+1]=1;
                ma2[i+1][j+1]=1;
            }
        }
    }
    int top=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ma[i][j]!=ma2[i][j])top=0;
        }
    }

    if(top==0){
        cout<<-1<<endl;
    }
    else{
        cout<<num<<endl;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(ma[i][j]==1 && ma[i+1][j]==1 && ma[i][j+1] && ma[i+1][j+1]){
                    cout<<i+1<<" "<<j+1<<endl;
                }
            }
        }
    }
 
    return 0;
}
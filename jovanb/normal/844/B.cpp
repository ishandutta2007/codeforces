#include <bits/stdc++.h>

using namespace std;
int mat[100][100];
int row[100][2];
int column[100][2];
int main()
{
    long long brojac=0,n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>mat[i][j];

        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            row[i][mat[i][j]]++;
        }

    }
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            column[j][mat[i][j]]++;
        }

    }
    brojac=n*m;
    for(i=0;i<n;i++){

        if(row[i][0]>1)brojac+=pow(2,row[i][0])-1-row[i][0];
        if(row[i][1]>1)brojac+=pow(2,row[i][1])-1-row[i][1];
    }
    for(j=0;j<m;j++){

        if(column[j][0]>1)brojac+=pow(2,column[j][0])-1-column[j][0];
        if(column[j][1]>1)brojac+=pow(2,column[j][1])-1-column[j][1];
    }
    cout<<brojac;
    return 0;
}
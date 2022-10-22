#include <bits/stdc++.h>

using namespace std;
char mat[100][100],ch[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,m,br=0,si,sj,vg,vdo,vde,vl,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='S'){si=i;sj=j;}
        }
    }
    cin>>ch;
    long k=strlen(ch);
    long posi;
    long posj;
    for(vg=0;vg<=3;vg++){
        for(vdo=0;vdo<=3;vdo++){
            for(vl=0;vl<=3;vl++){
                for(vde=0;vde<=3;vde++){
                    if(vg!=vdo && vg!=vl && vg!=vde && vdo!=vl && vdo!=vde && vl!=vde){
                        posi=si;
                        posj=sj;
                        for(i=0;i<k;i++){
                            if(ch[i]-'0'==vg)posi--;
                            if(ch[i]-'0'==vdo)posi++;
                            if(ch[i]-'0'==vl)posj--;
                            if(ch[i]-'0'==vde)posj++;
                            if(posi<0 || posi>=n || posj<0 || posj>=m || mat[posi][posj]=='#')break;
                            if(mat[posi][posj]=='E'){br++;break;}
                        }
                    }
                }
            }
        }
    }
    cout<<br;
    return 0;
}
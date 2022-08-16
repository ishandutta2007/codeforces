#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

#define REP(i,a) for (int i = 0; i < (a); i++)
typedef pair<int,int>PII;

int g[10][10];
int newg[10][10];
vector<set<int>>v;
char ans[20][3][20];
void printfloor(int ind, int pos) {
    REP(i,9) {
        ans[pos][0][2*i]='.';
        ans[pos][0][2*i-1]='#';

    }
    REP(i,9) {
        if (newg[ind][i]==0 && ind != i) {
            ans[pos][1][2*i]='#';
        } else {
            ans[pos][1][2*i]='.';
        }
        ans[pos][1][2*i-1]='#';
 
    }
    int z=0;
    for(auto x : v[ind]) {
        ans[pos][2][z++]='1' + x;
    }
    for (int i = z; i < 17; i++) {
        ans[pos][2][i]='.';
    }
}
void printblank(int ind,int pos) {
    REP(i,9) {
        if (ind == i) {
            ans[pos][0][2*i]='#';
        } else {
            ans[pos][0][2*i]='.';
        }
        if (i!=0) {
            ans[pos][0][2*i-1]='#';
        }
    }
    for (int j = 1; j < 3; j++) {
        REP(i,17) {
            ans[pos][j][i]='#';
        }
    }
}
int main() {
    int n;
    cin>>n;
    REP(i,n) {
        REP(j,n) {
            cin>>g[i][j];
        }
        
    }
    REP(i,n)REP(j,n)REP(k,n) {
        if (g[j][i] && g[i][k]) {
            g[j][k] = 1;
        }
    }
    int done[10];
    REP(i,10)done[i]=0;
    REP(i,n) {
        if (!done[i]) {
            done[i] = 1;
            set<int>temp;
            temp.insert(i);
            REP(j,10) {
                if (g[i][j]==1 && g[j][i]==1) {
                    temp.insert(j);
                    done[j] = 1;
                }
            }
            v.push_back(temp);
        }
    }
    /*cout<<"##COMP"<<endl;
    REP(i,v.size()) {
        for(auto x : v[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }*/
    REP(i,10)REP(j,10)newg[i][j]=0;
    REP(i,v.size()) {
        for (auto x : v[i])
        REP(j,10) {
            if (g[x][j]==1) {
                REP(k,v.size()) {
                    if (k != i && v[k].find(j) != v[k].end()) {
                        newg[i][k]=1;
                    }
                }
            }
        }
    }
    /*cout<<"### GRAPH"<<endl;
    REP(i,10) {
        REP(j,10) {
            cout<<newg[i][j]<<" ";
        }
        cout<<endl;
    }*/
    REP(i,10)done[i]=0;
    REP(i,v.size()) {
        int ind;
        REP(j,v.size()) {
            if (done[j])continue;
            bool found = true;
            REP(k,v.size()) {
                if (done[k] == 0 && newg[k][j]==1) {
                    found = false;
                }
            }
            if (found) {
                ind = j;
                break;
            }
        }
        done[ind]=1;

        printfloor(ind,2*i);

        printblank(ind,2*i+1);

    }
    cout<<17<<" "<<3<<" "<<v.size()*2<<endl;
    REP(i,v.size()*2) {
        REP(j,3) {
            REP(k,17) {
                cout<<ans[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
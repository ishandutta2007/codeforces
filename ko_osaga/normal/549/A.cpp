#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char str[55][55];
int n,m;

int trial(int x, int y){
    string s;
    s.push_back(str[x][y]);
    s.push_back(str[x+1][y]);
    s.push_back(str[x][y+1]);
    s.push_back(str[x+1][y+1]);
    sort(s.begin(),s.end());
    return s == "acef";
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    int ret = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            if(trial(i,j)) ret++;
        }
    }
    printf("%d",ret);
}
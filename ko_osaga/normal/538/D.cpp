#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int,int> pi;

char str[55][55];
int n;

char ret[101][101];
vector<pi> avail;

int cnt[101][101];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
        for (int j=0; j<n; j++){
            if(str[i][j] == 'o'){
                avail.push_back(pi(i,j));
            }
        }
    }
    memset(ret,'^',sizeof(ret));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(str[i][j] == '.'){
                for (int k=0; k<avail.size(); k++) {
                    int dx = i - avail[k].first;
                    int dy = j - avail[k].second;
                    ret[n - 1 + dx][n - 1 + dy] = '.';
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(str[i][j] == 'x'){
                int cnt = 0;
                for (int k=0; k<avail.size(); k++) {
                    int dx = i - avail[k].first;
                    int dy = j - avail[k].second;
                    if(ret[n-1+dx][n-1+dy] == '.') cnt++;
                }
                if(cnt == avail.size()){
                    puts("NO");
                    return 0;
                }
                for (int k=0; k<avail.size(); k++) {
                    int dx = i - avail[k].first;
                    int dy = j - avail[k].second;
                    if(ret[n-1+dx][n-1+dy] != '.') ret[n-1+dx][n-1+dy] = 'x';
                }
            }
        }
    }
    puts("YES");
    ret[n-1][n-1] = 'o';
    for (int i=0; i<2*n-1; i++) {
        for (int j=0; j<2*n-1; j++) {
            if(ret[i][j] == '^') ret[i][j] = '.';
            putchar(ret[i][j]);
        }
        puts("");
    }
}
#include <cstdio>
#include <vector>
using namespace std;

vector<int> arr[26][26];

char s1[200005], s2[200005];
int n;

int main(){
    scanf("%d",&n);
    scanf("%s %s",s1,s2);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if(s1[i] != s2[i]){
            arr[s1[i]-'a'][s2[i]-'a'].push_back(i+1);
            cnt++;
        }
    }
    for (int i=0; i<26; i++) {
        for (int j=i+1; j<26; j++) {
            if(arr[i][j].size() && arr[j][i].size()){
                printf("%d\n%d %d",cnt - 2,arr[i][j][0],arr[j][i][0]);
                return 0;
            }
        }
    }
    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            if(arr[i][j].size()){
                for (int k=0; k<26; k++) {
                    if(arr[j][k].size()){
                        printf("%d\n%d %d",cnt-1,arr[i][j][0],arr[j][k][0]);
                        return 0;
                    }
                }
            }
        }
    }
    printf("%d\n-1 -1",cnt);
}
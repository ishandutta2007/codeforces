#include <bits/stdc++.h>

using namespace std;

char s[1004];
int arr[5][5], chk[5][5];

int main(){
    scanf("%s", s); int len = strlen(s);
    for(int i=0;i<len;++i){
        int ff = 0;
        for(int x=0;x<4;++x){
            for(int y=0;y<4;++y){
                if(s[i]=='0'){
                    if(x<3&&arr[x][y]==0&&arr[x+1][y]==0){
                        arr[x][y] = arr[x+1][y] = 1;
                        for(int x=0;x<4;++x) if(arr[x][0]+arr[x][1]+arr[x][2]+arr[x][3]==4)
                            ff = 1;
                        for(int y=0;y<4;++y) if(arr[0][y]+arr[1][y]+arr[2][y]+arr[3][y]==4)
                            ff = 1;
                        arr[x][y] = arr[x+1][y] = 0;
                    }
                }
                else{
                    if(y<3&&arr[x][y]==0&&arr[x][y+1]==0){
                        arr[x][y] = arr[x][y+1] = 1;
                        for(int x=0;x<4;++x) if(arr[x][0]+arr[x][1]+arr[x][2]+arr[x][3]==4)
                            ff = 1;
                        for(int y=0;y<4;++y) if(arr[0][y]+arr[1][y]+arr[2][y]+arr[3][y]==4)
                            ff = 1;
                        arr[x][y] = arr[x][y+1] = 0;
                    }
                }
            }
        }
        for(int x=0;x<4;++x){
            int f = 0;
            for(int y=0;y<4;++y){
                if(s[i]=='0'){
                    if(x<3&&arr[x][y]==0&&arr[x+1][y]==0){
                        arr[x][y] = arr[x+1][y] = 1;
                        int a = 0;
                        for(int x=0;x<4;++x) if(arr[x][0]+arr[x][1]+arr[x][2]+arr[x][3]==4)
                            a = 1;
                        for(int y=0;y<4;++y) if(arr[0][y]+arr[1][y]+arr[2][y]+arr[3][y]==4)
                            a = 1;
                        if(!a&&ff){
                            arr[x][y] = arr[x+1][y] = 0;
                        }
                        else{
                            printf("%d %d\n", x+1, y+1); f = 1; break;
                        }
                    }
                }
                else{
                    if(y<3&&arr[x][y]==0&&arr[x][y+1]==0){
                        arr[x][y] = arr[x][y+1] = 1;
                        int a = 0;
                        for(int x=0;x<4;++x) if(arr[x][0]+arr[x][1]+arr[x][2]+arr[x][3]==4)
                            a = 1;
                        for(int y=0;y<4;++y) if(arr[0][y]+arr[1][y]+arr[2][y]+arr[3][y]==4)
                            a = 1;
                        if(!a&&ff){
                            arr[x][y] = arr[x][y+1] = 0;
                        }
                        else{
                            printf("%d %d\n", x+1, y+1); f = 1; break;
                        }
                    }
                }
            }
            if(f) break;
        }
        memset(chk, 0, sizeof(chk));
        for(int x=0;x<4;++x) if(arr[x][0]+arr[x][1]+arr[x][2]+arr[x][3]==4)
            chk[x][0] = chk[x][1] = chk[x][2] = chk[x][3] = 1;
        for(int y=0;y<4;++y) if(arr[0][y]+arr[1][y]+arr[2][y]+arr[3][y]==4)
            chk[0][y] = chk[1][y] = chk[2][y] = chk[3][y] = 1;
        for(int x=0;x<4;++x) for(int y=0;y<4;++y) arr[x][y] -= chk[x][y];
    }
    return 0;
}
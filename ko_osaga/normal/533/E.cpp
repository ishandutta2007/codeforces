#include <cstdio>
#include <algorithm>
using namespace std;

int n;
char str[100005], str2[100005];
char *p1, *p2;

int sol1(){
    int wrong = 0, pt = 0, pt2 = 0;
    // trial by calibration of one
    for (int i=0; i<n-1; i++) {
        if(p1[pt] != p2[pt2]){
            if(wrong == 0){
                pt++;
                if(p1[pt] != p2[pt2]){
                    pt2++;
                    if(p1[pt] != p2[pt2]) return 0;
                }
                wrong = 1;
            }
            else{
                pt2++;
                if(p1[pt] != p2[pt2]) return 0;
            }
        }
        pt++; pt2++;
    }
    return 1;
}

int main(){
    scanf("%d %s %s",&n,str,str2);
    p1 = str, p2 = str2;
    int ret = sol1();
    swap(p1,p2);
    ret += sol1();
    printf("%d",ret);
}
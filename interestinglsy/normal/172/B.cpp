#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 300010

using namespace std;

int a,b,m,r;
int book[MAX];

int main(){
	memset(book,0,sizeof(book));//1111
    cin >> a >> b >> m >> r;
    for (int i = 1;i < MAX;i++){
        r = (a * r + b) % m;	//
        if(book[r]){
            cout << i-book[r] << endl;
            break;
        }
        book[r] = i;
    }
    return 0;
    cout << "LSY  is  handsome!  :]";
}
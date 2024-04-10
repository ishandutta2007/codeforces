#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
int n, b[234567],c[234567],m,l=0,z=0,q=0;
vector <int> a[213456];

int main() {
	scanf("%d" , &n);

	for (int i =1; i <= n; i++){
		scanf("%d" , &m);
		z = 0; q = l;
		while(z<q){
            	  int mm=(z+q)/2;
		  if(a[mm].back()<m)q=mm;
		  else z=mm+1;
		 }
        a[z].push_back(m);
        l=max(l,z+1);
    }
    for (int i =0; i < l; i++){
        for (int j = 0; j < a[i].size(); j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
		
	return 0;
}
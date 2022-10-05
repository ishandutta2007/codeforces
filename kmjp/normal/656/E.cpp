#include <bits/stdc++.h>
using namespace std;

int N;
int A[101][101];

void hoge(int y,int x) {
	cin>>A[y][x];
}

int loop(int y,int x) {
	hoge(y,x);
	return (x<N-1)?loop(y,x+1):(y<N-1)?loop(y+1,0):0;
}
int loop2(int y,int x) {
	int r=(x<N-1)?loop2(y,x+1):(y<N-2)?loop2(y+1,y+2):0;
	return max(r,A[y][x]);
}

int dfs(int z,int x,int y) {
	A[x][y]=min(A[x][y],A[x][z]+A[z][y]);
	return (y<N-1)?dfs(z,x,y+1):(x<N-1)?dfs(z,x+1,0):(z<N-1)?dfs(z+1,0,0):0;
}

int main(int argc,char** argv){
	
	cin>>N;
	loop(0,0);
	dfs(0,0,0);
	cout<<loop2(0,1)<<endl;
}
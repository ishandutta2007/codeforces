#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <bitset>
#define pb push_back
#define mp make_pair
#define INF (1e9)
#define LINF (1e18)
#define uint unsigned int
#define msn(_data,_val) memset(_data,_val,sizeof(_data))
#define ms(_data) memset(_data,0,sizeof(_data))
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
#define out cout << 
#define in cin >> 
#define print(_num) printf("%d\n",_num);
#define ln printf("\n");
#define read(_num) scanf("%d",&_num);
using namespace std;
#define MAXPOS 400
#define MAXC 50

int n , q , c;
int maxx=-1 , maxy=-1;

ll sum[MAXPOS][MAXPOS][MAXC];
vector<int> data[MAXPOS][MAXPOS];
bool isstar[MAXPOS][MAXPOS];

void nexttime(){
	for( int i = 0 ; i < MAXPOS ; i++ )
		for( int j = 0 ; j < MAXPOS ; j++ )
			if( isstar[i][j] ){
				for( int k = 0 ; k < data[i][j].size() ; k++ ){
					data[i][j][k]++;
					if(data[i][j][k]>c)data[i][j][k]=0;
				}
			}
}
void calsum(){
	ms(sum);
	for( int time = 0 ; time <= c+1 ; time++ ){
		sum[1][1][time] = 0;
		for( int k = 0 ; k < data[1][1].size() ; k++ )
			sum[1][1][time] += data[1][1][k];
		for( int i = 2 ; i < MAXPOS ; i++ ){
			sum[1][i][time] = sum[1][i-1][time];
			for( int k = 0 ; k < data[1][i].size() ; k++ )
				sum[1][i][time] += data[1][i][k];
		}
		for( int i = 2 ; i < MAXPOS ; i++ ){
			sum[i][1][time] = sum[i-1][1][time];
			for( int k = 0 ; k < data[i][1].size() ; k++ )
				sum[i][1][time] += data[i][1][k];
		}
		for( int i = 2 ; i < MAXPOS ; i++ )
			for( int j = 2 ; j < MAXPOS ; j++ ){
				sum[i][j][time] = sum[i][j-1][time]+sum[i-1][j][time]-sum[i-1][j-1][time];
				for( int k = 0 ; k < data[i][j].size() ; k++ )
					sum[i][j][time] += data[i][j][k];
			}
		nexttime();
	}
}
ll solve( int x1 , int y1 , int x2 , int y2 , ll time ){
	//cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
	time = time % (c+1);
	//cout << time << endl;
	ll ans = sum[y1][x1][time];
	//cout << "[Ans] " << ans << endl;
	//cout << sum[y1][x2-1][time] << " " << sum[y2-1][x2][time] << endl;
	if( x2 >= 1 ) ans -= sum[y1][x2-1][time];
	if( y2 >= 1 ) ans -= sum[y2-1][x1][time];
	if( x2 >= 1  &&  y2 >= 1 ) ans += sum[y2-1][x2-1][time];
	return ans;
}

int main(){
	//freopen("C.txt","r",stdin);
	ms(data); ms(isstar);
	scanf("%d %d %d",&n,&q,&c);
	for( int i = 1 ; i <= n ; i++ ){
		int x , y , bri ;
		scanf("%d %d %d",&x,&y,&bri);
		data[y][x].pb(bri);
		maxx = max( maxx , x );
		maxy = max( maxy , y );
		isstar[y][x] = 1;
	}
	
	calsum();
	//for( int i = 1 ; i <= maxy ; i++ ){
	//	for( int j = 1 ; j <= maxx ; j++ )
	//		if(isstar[i][j])
	//			cout << sum[i][j][1] << " ";
	//		else cout << ". ";
	//	cout << endl;
	//}
	for( int i = 1 ; i <= q ; i++ ){
		int x1,y1,x2,y2;
		ll t;
		scanf("%I64d %d %d %d %d",&t,&x2,&y2,&x1,&y1);
		printf("%I64d\n",solve(x1,y1,x2,y2,t));
	}
	return 0;
}
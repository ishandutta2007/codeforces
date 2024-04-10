#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define INF (1e+8)
#define LINF 9999999999999999
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
using namespace std;

int vv[10][5];	// 
int v[10][5];	// 
int x[10];	//	x

void roll( int pos ){
	switch(x[pos]){
		case 1:
			v[pos][1] = vv[pos][1];
			v[pos][2] = vv[pos][2];
			v[pos][3] = vv[pos][3];
			break;
		case 2:
			v[pos][1] = vv[pos][1];
			v[pos][2] = vv[pos][3];
			v[pos][3] = vv[pos][2];
			break;
		case 3:
			v[pos][1] = vv[pos][2];
			v[pos][2] = vv[pos][1];
			v[pos][3] = vv[pos][3];
			break;
		case 4:
			v[pos][1] = vv[pos][2];
			v[pos][2] = vv[pos][3];
			v[pos][3] = vv[pos][1];
			break;
		case 5:
			v[pos][1] = vv[pos][3];
			v[pos][2] = vv[pos][2];
			v[pos][3] = vv[pos][1];
			break;
		case 6:
			v[pos][1] = vv[pos][3];
			v[pos][2] = vv[pos][1];
			v[pos][3] = vv[pos][2];
			break;
		default:
			cout << "[Error] x[" << pos << "] is not in [1,6]\n";
			break;	 
	}
}
void next_pailie(){
	int pos = 8;
	while( 1 ){
		x[pos]++;
		if( x[pos] < 1 ) cout << "[Error] x[" << pos << "] < 1\n";
		if( x[pos] <= 6 ){
			roll( pos );
			break;
		}
		x[pos] -= 6;
		roll( pos );
		pos--;
	}
}
void print_pailie(){
	//cout << "[PaiLie]\n";
	for( int i = 1 ; i <= 8 ; i++ )
		printf("%d %d %d\n",v[i][1],v[i][2],v[i][3]);
}

ll sqr( ll t ){
	return (ll)(t*t);
}
int app[10];
ll yingshe[10];
int pos;
int find( ll x ){
	for( int i = 1 ; i <= pos ; i++ )
		if( yingshe[i] == x )
			return i;
	return 0;
}
bool ok(){
	ll firstdis = -1;
	pos = 1;
	ms(app); ms(yingshe);
	
	for( int i = 1 ; i <= 8 ; i++ )
		for( int j = i+1 ; j <= 8 ; j++ ){
			ll dis = sqr(v[i][1]-v[j][1])+sqr(v[i][2]-v[j][2])+sqr(v[i][3]-v[j][3]);
			//cout << v[i][2] << " " << v[j][2] << " " << v[i][2]-v[j][2] << " " << sqr(-196608) << endl;
			if( dis == 0 ){
				//cout << "Exitcode 1: ";
				//printf(" The dis between Pos  %d  and  %d  is 0\n",i,j);
				return 0;
			}
			if( firstdis == -1 ) firstdis = dis;
			//cout << "Dis Between " << i << " and " << j << ":  " << dis << endl;
			//printf("Firstpos: (%d,%d,%d)	Secondpos: (%d,%d,%d)\n",v[i][1],v[i][2],v[i][3],v[j][1],v[j][2],v[j][3]);
			if( !find(dis) ){
				app[ pos ] = 1;
				yingshe[ pos ] = dis;
				pos++;
				if( pos > 4 ){
					//cout << "Exitcode 2\n";
					return 0;
				}
			}else{
				app[ find( dis ) ]++;
			}
		}
	//cout << "[ALL IN ALL]\n";
	//for( int i = 1; i <= pos;i++ )
	//	printf("%d\n",app[i]);
	if( (app[2] == 12  &&  app[3] == 12  &&  app[1] == 4) 	||
		(app[3] == 12  &&  app[1] == 12  &&  app[2] == 4) 	||
		(app[2] == 12  &&  app[1] == 12  &&  app[3] == 4) ){
		//cout << firstdis << endl;
		return 1;
	}
	else return 0;
}

int main(){
///	freopen("D.txt","r",stdin);
	//cout << "[Main]: Start to solve\n";
	for( int i = 1; i <= 8 ; i++ ){
		scanf("%d %d %d",&vv[i][1],&vv[i][2],&vv[i][3]);
		x[i] = 1;
		roll( i );
	}
	//cout << "[Main]: Start to solve\n";
	for( int i = 1; i <= 1679616 ; i++ ){		//1679616
		//if( i % 10000 == 0 ) cout << i << endl;
		if( ok() ){
			printf("YES\n");
			print_pailie();
			return 0;
		}
		next_pailie();
	}
	printf("NO\n");
	return 0;
}
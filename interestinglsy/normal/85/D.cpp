/*
				
	
				
	
		 --[mod]InterestingLSY 
*/
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
#define pb push_back
#define mp make_pair
#define INF 9999999
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
#define MAXN 100100

class Node{
public:
	Node *l = NULL , *r = NULL;
	ll sum[10];		// %5 =0 =1 =2 =3 =4
	int fix, num;
	int size = 1;
};

int getsize( Node *pos ){
	return pos ? pos->size : 0;
}

void update( Node *&pos ){
	if( !pos ) return;
	
	int pluson = 0;
	pos->size = getsize( pos->l ) + 1 + getsize( pos->r );
	
	if( pos->l ){
		for( int i = 0; i < 5; i++ ) pos->sum[i] = pos->l->sum[i];
		pluson = pos->l->size % 5;
	}else{
		for( int i = 0; i < 5; i++) pos->sum[i] = 0;
	}
	
	pos->sum[pluson] += pos->num;
	
	if( pos->r )
		for( int i = 0; i < 5; i++)
			pos->sum[ (i+pluson+1) % 5 ] += pos->r->sum[ i ];
}

void merge( Node *l , Node *r , Node *&final ){
	if( !l ){
		final = r;
		return;
	}
	if( !r ){
		final = l;
		return;
	}
	if( l->fix > r->fix ){
		merge( l->r , r , l->r );
		final = l;
	}else{
		merge( l , r->l , r->l );
		final = r;
	}
	update( final );
}
void split( Node *pos , Node *&l , Node *&r , int num ){
	if( !pos ){
		l = r = NULL;
		return;
	}
	if( num < pos->num ){
		split( pos->l , l , pos->l , num );
		r = pos;
	}else{
		split( pos->r , pos->r , r , num );
		l = pos;
	}
	update( pos );
}

Node *root = NULL;

void newnode( int num ){
	Node *left, *right, *now;
	split( root , left , right , num );
	
	now = new Node;
	now->l = now->r = NULL;
	now->num = num;
	now->fix = rand(); now->size = 1;
	update( now );
	
	merge( left , now , root );
	merge( root , right , root );
}
void delnode( Node *&pos , int num ){
	if( pos->num == num )
		merge( pos->l , pos->r , pos );			//
	else if( num < pos->num )
		delnode( pos->l , num );
	else
		delnode( pos->r , num );
	update( pos ); 
}
void printpos(Node *pos,int deep){
	if( !pos ) return;
	for(int i = 1;i < deep;i++) cout << "\t";
	cout << "NUM: " << pos->num << "  ";
	cout << "FIX: " << pos->fix << endl;
	for(int i = 1;i < deep;i++) cout << "\t";
	cout << "SIZE: " << pos->size << "   ";
	if( pos->l ) cout << "  L  ";
	if( pos->r ) cout << "  R  ";
	cout << "    [END]";
	cout << endl;
}
void printtree(Node *pos,int deep){
	if( pos->r ) printtree(pos->r,deep+1);
	printpos(pos,deep);
	if( pos->l ) printtree(pos->l,deep+1);
}
int n;
char cmd[9];
int x;
int main(){
	//freopen("1.txt","r",stdin);
	srand( 19720430 );
	scanf("%d",&n);
	for(int ni = 1;ni <= n;ni++){
		//cout << "----------------NEWCMD-----------------" << endl;
		scanf("%s",&cmd);
		if(cmd[0] == 'a'){
			scanf("%d",&x);
			newnode( x );
		}
		if(cmd[0] == 'd'){
			scanf("%d",&x);
			delnode( root , x );
		}
		if(cmd[0] == 's'){
			if( root ) printf( "%I64d\n" , root->sum[2] );
			else printf( "0\n" );
		}
		//printtree( root , 1 );
	}
	return 0;
}
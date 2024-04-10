#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define ll long long
#define ms(lsy) memset(lsy,0,sizeof(lsy))
using namespace std;

int mem[110];		//mem[i] i
int t,ti,m,maxid;
bool nuse[23333+1];
bool nalive[23333+1];

void __init__(){
	ms(mem);
	ms(nuse);
	ms(nalive);
}
void del(int pos){
	int k;
	for(k = pos;k <= m;k++)
		mem[k] = mem[k + 1];
}
int get_id(){	//id
	int k;
	for(k = 1;k <= 23333;k++)
		if((!nuse[k]) && (!nalive[k])){
			nuse[k] = 1;
			nalive[k] = 1;
			maxid = k;
			return k;
		}
	return 0; 
}
void alloc(int data){
	int k,j,start = 0;
	bool done;
	for(k = 1;k <= m;k++){
		if(!mem[k]){
			done = true;
			for(j = 0;j < data;j++)
				if(mem[k+j] || k+j > m){done = false;break;}
			if(done){
				start = k;
				break;
			}
		}
	}
	if(!start){
		cout << "NULL\n";
	}else{
		int id = get_id();
		cout << id << endl;
		for(j = 0;j < data;j++) mem[start + j] = id;
		id++;
	}
}
void erase(int data){
	int k,j;
	if(data <= 0 || data > maxid){
		cout << "ILLEGAL_ERASE_ARGUMENT\n";
		return;
	}
	if(!(nuse[data]) || (!nalive[data])){
		cout << "ILLEGAL_ERASE_ARGUMENT\n";
		return;
	}
	for(k = 1;k <= m;k++)
		if(mem[k] == data){
			j = k;
			while(mem[j] == data)
				mem[j] = 0;
		}
	nalive[data] = 0;
}
void defragment(){
	int k,delnum=0;
	for(k = 1;k <= m;k++)
		while(!mem[k] && delnum <= m){
			del(k);
			delnum++;
		}
}
int main(){
	__init__();
	//freopen("7B.txt","r",stdin);
	cin >> t >> m;
	for(ti = 1;ti <= t;ti++){
		string cmd;
		int data;
		cin >> cmd;
		if(cmd == "alloc"){
			cin >> data;
			alloc(data);
		}
		if(cmd == "erase"){
			cin >> data;
			erase(data);
		}
		if(cmd == "defragment")
			defragment();
		//for(int ii=1;ii<=m;ii++)cout<<mem[ii];cout<<endl;
	}
	return 0;
	cout << "LSY IS HANDSOME\n";
}
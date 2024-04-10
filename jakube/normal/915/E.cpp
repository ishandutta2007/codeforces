#include <bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	int todo=0;
	node * left=NULL;
	node * right=NULL;
};


vector<node> tree;
int cnt=0;
void update(node * curr,int s,int e,int rs,int re,int k){
	if(e<rs or s>re or s>e){
		return;
	}

    if(re>=e and rs<=s){
    	if(k==1){
    		curr->data=0;
    	}
    	else{
    		curr->data=(e-s+1);
    	}
    	curr->todo=k;
    	return;
    }
    int mid=s+(e-s)/2;
    //make a space for left part
    if(curr->left==NULL){
    	tree.push_back({0,0,NULL,NULL});
    	curr->left=&tree[cnt];
    	cnt++;
    }
    if(curr->right==NULL){
    	tree.push_back({0,0,NULL,NULL});
    	curr->right=&tree[cnt];
    	cnt++;
    }

    if(curr->todo==1){
    	curr->left->data=0;
    	curr->left->todo=1;
    	curr->right->data=0;
    	curr->right->todo=1;
    	curr->todo=0;
    }

    if(curr->todo==2){
    	curr->left->data=(mid-s+1);
    	curr->left->todo=2;
    	curr->right->data=(e-mid);
    	curr->right->todo=2;
    	curr->todo=0;
    }

    update(curr->left,s,mid,rs,re,k);
    update(curr->right,mid+1,e,rs,re,k);
    curr->data=curr->left->data+curr->right->data;
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	tree.reserve(15000010);
	tree.push_back({n,2,NULL,NULL});
	cnt++;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		update(tree.data(),1,n,l,r,k);
		cout<<tree.front().data<<'\n';
	}
    return 0;
}
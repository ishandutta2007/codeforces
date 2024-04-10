#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
struct node{
    int val,cnt,height;
    node* left;
    node* right;
};
node* newnode(int x){
    node* temp=new node;
    temp->left=temp->right=NULL;
    temp->val=x;
    temp->cnt=1;
    temp->height=1;
    return temp;
}
class SET{
public:
    int n;
    node* root;
    SET(){
        n=0;
        root=NULL;
    }
    int hgt(node* head){
        if(head==NULL) return 0;
        return head->height;
    }
    node* rotateleft(node* x){
        node* y=x->right;
        node* t=y->left;
        y->left=x;
        x->right=t;
        x->height=max(hgt(x->left),hgt(x->right))+1;
        y->height=max(hgt(y->left),hgt(y->right))+1;   
        return y;
    }
    node* rotateright(node* x){
        node* y=x->left;
        node* t=y->right;
        y->right=x;
        x->left=t;
        x->height=max(hgt(x->left),hgt(x->right))+1;
        y->height=max(hgt(y->left),hgt(y->right))+1;   
        return y;
    }
    int balance(node* head){
        return hgt(head->left)-hgt(head->right);
    }
    node* insertutil(node* head,int x){
        if(head==NULL) return newnode(x);
        if(head->val==x){
            head->cnt++;
            n--;
            return head;
        }
        if(head->val>x) head->left=insertutil(head->left,x);
        else head->right=insertutil(head->right,x);
        head->height=1+max(hgt(head->left),hgt(head->right));
        int b=balance(head);
        if(b>1){
            if(head->left->val>x){
                return rotateright(head);
            }
            else if(head->left->val<x){
                head->left=rotateleft(head->left);
                return rotateright(head);
            }
        }
        else if(b<-1){
            if(head->right->val<x){
                return rotateleft(head);
            }
            else if(head->right->val>x){
                head->right=rotateright(head->right);
                return rotateleft(head);
            }
        }
        return head;
    }
    void insert(int x){
        n++;
        root=insertutil(root,x);
    }
    int count(int x){
        node* head=root;
        while(1){
            if(head->val==x) return head->cnt;
            if(head->val>x){
                head=head->left;
            }
            else{
                head=head->right;
            }
            if(head==NULL) return 0;
        }
    }
    node* min(node* head){
        while(head->left!=NULL){
            head=head->left;
        }
        return head;
    }
    node* delutil(node* head,int x){
        if(head==NULL) return head;
        if(head->val==x){
            head->cnt--;
            if(head->cnt>0){
                n++;
                return head;
            }
            if(head->left==NULL){
                node* temp=head->right;
                if(temp==NULL){
                    temp=head;
                    head=NULL;
                }
                else *head=*temp;
                free(temp);
            }
            else if(head->right==NULL){
                node* temp=head->left;
                *head=*temp;
                free(temp);
            }
            else{                
                node* temp=min(head->right);
                swap(head->val,temp->val);
                head->right=delutil(head->right,x);
            }
        }
        else if(head->val>x){
            head->left=delutil(head->left,x);
        }
        else{
            head->right=delutil(head->right,x);
        }
        if(head==NULL) return head;
        head->height=1+max(hgt(head->left),hgt(head->right));
        int b=balance(head);
        if(b>1){
            if(balance(head->left)>=0){
                return rotateright(head);
            }
            else if(balance(head->left)<0){
                head->left=rotateleft(head->left);
                return rotateright(head);
            }
        }
        else if(b<-1){
            if(balance(head->right)<=0){
                return rotateleft(head);
            }
            else if(balance(head->right)>0){
                head->right=rotateright(head->right);
                return rotateleft(head);
            }
        }
        return head;
    }
    void del(int x){
        root=delutil(root,x);
    }
    int size(){
        return n;
    }
    void disp(){
        stack<node*> stk;
        node* head=root;
        while(!stk.empty() || head!=NULL){
            while(head!=NULL){
                stk.push(head);
                head=head->left;
            }
            node* temp=stk.top();
            stk.pop();
            cout<<temp->val<<" "<<temp->cnt<<" "<<temp->height<<endl;
            head=temp->right;
        }
        cout<<endl;
    }
};

void solve(){
    SET st;
    int n;
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        if(x) st.insert(x);
    }
    cout<<st.size()<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
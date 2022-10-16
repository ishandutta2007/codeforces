#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;
    int num_counts=0;
    vector<int> res_ind;
    int pre_ind=1,status=0,start;
    if(n<=(2*k)+1){
        cout<<1<<endl;
        cout<<(n/2)+1<<endl;
        status=1;
    }
    if(!status){
        pre_ind+=k;
        start=pre_ind;
        while(pre_ind<n){
            //cout<<pre_ind<<endl;
            if(pre_ind+k<=n){
                num_counts+=1;
                res_ind.push_back(pre_ind);
                int update=pre_ind+(2*k)+1;
                if(update<=n){
                    pre_ind+=((2*k)+1);
                    if(pre_ind==n){
                        num_counts+=1;
                        res_ind.push_back(pre_ind);
                    }
                }
                else if(pre_ind+k==n){
                    break;
                }
                else{
                    res_ind.clear();
                    pre_ind=start-1;
                    start-=1;
                    num_counts=0;
                }
            }
            else{
                num_counts+=1;
                res_ind.push_back(pre_ind);
                break;
            }
        }
        cout<<num_counts<<endl;
        for(int i=0;i<res_ind.size();++i){
            cout<<res_ind[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
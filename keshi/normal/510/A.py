a,b=map(int,input().split())
for i in range(1,a+1):
    if i%2:
        print("#"*b)
    else:
        if i%4==0:
            print("#",end='')
        print('.'*(b-1),end='')
        if i%4:
            print("#",end='')
        print()
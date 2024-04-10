def get():
    return list(map(int,input().split()))
b,k=get()
a=get()
if b%2==0:
    if a[-1]%2:
        print('odd')
    else:
        print('even')
else:
    if sum(a)%2==0:
        print('even')
    else:
        print('odd')
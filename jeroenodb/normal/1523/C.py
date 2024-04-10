for h in range(int(input())):
    n=int(input())
    s=[]
    for i in range(n):
        j = int(input())
        if j==1:
            s.append(j)
        else:
            while j-s[-1]!=1:
                s.pop()
            s[-1]=j
        print('.'.join(map(str, s)))
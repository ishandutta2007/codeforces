l=int(input())
for i in range(l):
    word=input()
    s=set()
    n=1
    for l in word:
        s.add(l)
        if len(s)>3:
            #print(s)
            n+=1
            s=set(l)
    print(n)
a=input()
b=input()
if len(b)>len(a):
    print("need tree")
elif len(a)==len(b):
    if sorted(a)==sorted(b):
        print("array")
    else:
        print("need tree")
else:
    if b in a:
        print("automaton")
    else:
        d=set(b)
        f=1
        for i in d:
            if b.count(i)>a.count(i):
                f=0
                break
        if f:
            h=b
            l=0
            while f:
                if h[l] in a:
                    a=a[a.index(h[l])+1:]
                    l+=1
                    if l==len(b):
                        print("automaton")
                        f=0
                else:
                    f=0
            if l!=len(b):
                print("both")
        else:
            print("need tree")
st=set()
g=["think","great","touch","bad","cool"]
w=["are","way","die","even","worse","terrible"]
for i in range(10):
    print(i,flush=True)
    a=input().split()
    for j in a:
        st.add(j)
    for r in st:
        if r in w:
            print("grumpy",flush=True)
            exit()
    for r in st:
        if r in g:
            print("normal",flush=True)
            exit()
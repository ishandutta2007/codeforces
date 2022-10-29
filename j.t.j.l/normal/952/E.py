n=int(input())
p = 0
q = 0
for i in range(n):
    x,y=input().split()
    if y == 'soft':
        p += 1
    else:
        q += 1
for i in range(1, 100):
    # soft::
    if (((i * i + 1) // 2 >= p) and ((i * i) // 2 >= q)) or (((i * i + 1) // 2 >= q) and ((i * i) // 2 >= p)):
        print(i)
        break
n = input()
v = [int(x) for x in input().split()]
s = sum(v)
psum = 0
for i, x in enumerate(v):
    psum += x
    if psum * 2 >= s:
        print(i+1)
        break
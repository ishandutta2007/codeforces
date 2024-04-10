n = int(input())
k = int(input())
out = 0
base = 1
while (k != 0):
    big = 10000000000
    while (k%big) >= n and big > 10:
        big //= 10
    
    out += (k%big)*base
    base *= n 
    cpy = big 
    while ((k%big) < cpy//10 and cpy > 10):
        #print("yeet")
        cpy //= 10
    #print("done", big, k)
    big = cpy
    k //= big 
print(out)
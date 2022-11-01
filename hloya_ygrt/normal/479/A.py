def get():
    return int(input())
a = get()
b = get()
c = get()
print(max(max((a+b)*c,a*(b+c)),max(a*b*c,a+b+c)))
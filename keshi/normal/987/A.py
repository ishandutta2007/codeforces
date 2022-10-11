n=int(input())
a={"purple":"Power","green":"Time","blue":"Space","orange":"Soul","red":"Reality",
   "yellow":"Mind"}
b=["Power","Time","Space","Soul","Reality","Mind"]
for i in range(n):
    b.remove(a[input()])
print(len(b))
for i in b:
    print(i)
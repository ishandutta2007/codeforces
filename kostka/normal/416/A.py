n = int(input())

lewo = -2*(10**9); prawo = 2*(10**9)

for i in range(n):
    buf = input().split(" ")
    liczba = int(buf[1])
    wynik = buf[2]
    if (buf[0]==">=" and wynik=="Y") or (buf[0]=="<" and wynik=="N"):
        lewo = max(lewo, liczba)
    if (buf[0]=="<=" and wynik=="Y") or (buf[0]==">" and wynik=="N"):
        prawo = min(prawo, liczba)
    if (buf[0]=="<" and wynik=="Y") or (buf[0]==">=" and wynik=="N"):
        prawo = min(prawo, liczba-1)
    if (buf[0]==">" and wynik=="Y") or (buf[0]=="<=" and wynik=="N"):
        lewo = max(lewo, liczba+1)

#print(lewo, prawo)
if(lewo > prawo):
    print("Impossible")
else:
    print(lewo)